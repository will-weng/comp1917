#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

#include "mandelbrot.h"

#define ESCAPED 1
#define STAYED 0
#define RANGE 2
#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 2

#define BMP_FILE "chess.bmp"

typedef struct _complex {
	double real;
	double imaginary;
} complex;

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket);
int modulus (complex complexNum);
unsigned char stepsToRed (int steps);
unsigned char stepsToGreen (int steps);
unsigned char stepsToBlue (int steps);

// after serving this many pages the server will halt

int main (int argc, char *argv[]) {
			
	printf ("************************************\n");
	printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
	printf ("Serving bmps since 2012\n");   
	 
	int serverSocket = makeServerSocket (DEFAULT_PORT);   
	printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
	printf ("************************************\n");
	 
	char request[REQUEST_BUFFER_SIZE];
	 
	int numberServed = 0;
	while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {

		printf ("*** So far served %d pages ***\n", numberServed);
			
		int connectionSocket = waitForConnection (serverSocket);
		// wait for a request to be sent from a web browser, open a new
		// connection for this conversation
			
		// read the first line of the requefst sent by the browser  
		int bytesRead;
		bytesRead = read (connectionSocket, request, (sizeof request)-1);
		assert (bytesRead >= 0); 
		// were we able to read any data from the connection?
						
		// print entire request to the console 

        int counter = 0;
        
        while(request[]



/*

        //printf ("%c\n", request[10]);
        int counter = 0;
        char output[200];
        while (request[counter] != '_') {
            counter++;                    
        }        
        printf("%d\n",counter);
        //printf("%s\n",counter[0]);
        strncpy ( output, &request[11], counter-2 );
        printf ("%s\n", output);
        counter++;
        int counter2=0;
        while (request[counter] != '_') {
            counter++;
            counter2++;                    
        }  
        strncpy ( output, &request[counter+2], counter2 );
        printf ("%s\n", output);
*/





		printf (" *** Received http request ***\n %s\n", request);
			
		//send the browser a simple html page using http
		printf (" *** Sending http response ***\n");
		serveBMP(connectionSocket);
			
		// close the connection after sending the page- keep aust beautiful
		close(connectionSocket);
			
		numberServed++;
	} 
	
	// close the server connection after we are done- keep aust beautiful
	printf ("** shutting down the server **\n");
	close (serverSocket);

	return EXIT_SUCCESS; 
}

void serveBMP (int socket) {
	char* message;
	 
	// first send the http response header
	 
	// (if you write stings one after another like this on separate
	// lines the c compiler kindly joins them togther for you into
	// one long string)
	message = "HTTP/1.0 200 OK\r\n"
								"Content-Type: image/bmp\r\n"
								"\r\n";
	printf ("about to send=> %s\n", message);
	write (socket, message, strlen (message));
	 
	// now send the BMP
	int zoom = 8;
	double xInput = 0.0;
	double yInput = 0.0;
	//printf ("Enter a zoom level: ");
	//scanf ("%d", &zoom);
	//printf ("Enter an X value: ");
	//scanf ("%lf", &xInput);
	//printf ("Enter a Y value: ");
	//scanf ("%lf", &yInput);

	double x, y;
	x = xInput - pow (2, -1*zoom) * 256;
	y = yInput - pow (2, -1*zoom) * 256;
	
	unsigned char bmp[786486] = {
		/* BMP Header */
		0x42,0x4d, 
		0x36,0x00,0x0c,0x00, /* Size of BMP file set as 786486 */
		0x00,0x00,0x00,0x00, 
		0x36,0x00,0x00,0x00,
		/* DIB Header */
		0x28,0x00,0x00,0x00,
		0x00,0x02,0x00,0x00, /* Width set as 512 */
		0x00,0x02,0x00,0x00, /* Height set as 512 */
		0x01,0x00,
		0x18,0x00,
		0x00,0x00,0x00,0x00,
		0x24,0x00,0x0c,0x00, /* Size of pixel array set as 786432 */
		0x13,0x0b,0x00,0x00,
		0x13,0x0b,0x00,0x00,
		0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,
		/* Pixel Array */ 
		0x99};

    //printf("%d\n", bmp[54]);

	int counter = 54;
	/*while ( counter < 786486 ) {
		if (counter < 393243)
			bmp[counter] = 0x00;
		else
			bmp[counter] = 0xff;
		counter++;
	}*/

	while (y < yInput + pow (2, -1*zoom) * 256) {
		while (x < xInput + pow (2, -1*zoom) * 256) {
			if (escapeSteps (x, y) < 256) {
				//printf (" ");
				bmp[counter] = stepsToRed (escapeSteps (x, y));
				bmp[counter+1] = stepsToGreen (escapeSteps (x, y));
				bmp[counter+2] = stepsToBlue (escapeSteps (x, y));
			} else {
				//printf ("*");
				bmp[counter] = 0x00;
				bmp[counter+1] = 0x00;
				bmp[counter+2] = 0x00;
			}
			x += pow (2, -1*zoom);
			counter += 3;
		}
		x = xInput - pow (2, -1*zoom) * 256;
		//printf ("\n");
		y += pow (2, -1*zoom);
	}


	write (socket, bmp, sizeof(bmp));
}


// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
	
	// create socket
	int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
	assert (serverSocket >= 0);   
	// error opening socket
	
	// bind socket to listening port
	struct sockaddr_in serverAddress;
	memset ((char *) &serverAddress, 0,sizeof (serverAddress));
	
	serverAddress.sin_family      = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port        = htons (portNumber);
	
	// let the server start immediately after a previous shutdown
	int optionValue = 1;
	setsockopt (
		serverSocket,
		SOL_SOCKET,
		SO_REUSEADDR,
		&optionValue, 
		sizeof(int)
	);

	int bindSuccess = 
		bind (
			 serverSocket, 
			 (struct sockaddr *) &serverAddress,
			 sizeof (serverAddress)
		);
	 
	assert (bindSuccess >= 0);
	// if this assert fails wait a short while to let the operating 
	// system clear the port before trying again
	 
	return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
	// listen for a connection
	const int serverMaxBacklog = 10;
	listen (serverSocket, serverMaxBacklog);
	 
	// accept the connection
	struct sockaddr_in clientAddress;
	socklen_t clientLen = sizeof (clientAddress);
	int connectionSocket = 
		accept (
			serverSocket, 
			(struct sockaddr *) &clientAddress, 
			&clientLen
		);
	
	assert (connectionSocket >= 0);
	// error on accept
	 
	return (connectionSocket);
}

//function that counts how many iteration to escape
int escapeSteps(double x, double y) {

	complex point = {x, y};
	complex pointTemp = {x, y};
	complex constant = {x, y};

	int steps = 1;

	while(modulus(point) == STAYED && steps <= 255) {

		pointTemp.real = point.real;
		pointTemp.imaginary = point.imaginary;

		point.real = pointTemp.real*pointTemp.real -
					 pointTemp.imaginary*pointTemp.imaginary + 
					 constant.real;
		point.imaginary = pointTemp.imaginary*pointTemp.real*2 + 
						  constant.imaginary;

		steps++;
	}

	return steps;
}

// function that calculates the modulus of a point
int modulus(complex complexNum) {

	double real = complexNum.real;
	double imaginary = complexNum.imaginary;
	double modulus;

	modulus = sqrt(real*real + imaginary*imaginary);

	//printf("%f\n", modulus);

	int test;
	test = 0;

	if(modulus <= RANGE) {
		test = STAYED;
	} else {
		test = ESCAPED;
	}
	return test;
}

unsigned char stepsToRed (int steps) { 
    int color;
   if(steps > 0 && steps < 43) {
      color = 255;
   } else if(steps > 42 && steps < 85) {
      color = 255 - 6 * (steps - 42);
   } else if(steps > 84 && steps < 169) {
      color = 0;
   } else if(steps >168 && steps < 211) {
      color = 6 * (steps - 168);
   } else {
      color = 255;
   } 
   return color;
}

unsigned char stepsToBlue (int steps) {
    int color;
    if(steps > 0 && steps < 85) {
      color = 0;
   } else if(steps > 84 && steps < 127) {
      color = 6 * (steps - 86);
   } else if(steps > 126 && steps < 214) {
      color = 255;
   } else { 
      color = 255 - 6 * (steps - 214);
   }
   return color;
}

unsigned char stepsToGreen (int steps) {
    int color;
    if(steps > 0 && steps < 43) {
      color = 6 * (steps - 0);
   } else if(steps > 42 && steps < 127) {
      color = 255;
   } else if(steps > 126 && steps < 169) {
      color = 255 - 6 * (steps - 126);
   } else { 
      color = 0;
   } 
   return color;
}

