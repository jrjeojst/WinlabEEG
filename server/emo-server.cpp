/* A simple server in the internet domain using TCP
   The port number is passed as an argument 
   This version runs forever, forking off a separate 
   process for each connection
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <map>
#include <deque>
#include <string>
#include <utility>
#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef unsigned char uchar;
static const uchar ckey[] = "\x31\x00\x39\x54\x38\x10\x37\x42\x31\x00\x39\x48\x38\x00\x37\x50";

using namespace std;

void Decrypt32(uchar *in, uchar *out)
{
    static int firstRun = 1;
    static AES_KEY decryptKey;

    if (firstRun == 1)
    {
        AES_set_decrypt_key(ckey, 128, &decryptKey);
        firstRun = 0;
    }   

    AES_ecb_encrypt(in, out, &decryptKey, AES_DECRYPT);
    AES_ecb_encrypt(&in[AES_BLOCK_SIZE], &out[AES_BLOCK_SIZE], &decryptKey, AES_DECRYPT);

 
}

void dostuff(int); /* function prototype */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, pid;
     socklen_t clilen;
     struct sockaddr_in serv_addr, cli_addr;
	
     if (argc < 2)
       {
         printf("No port provided, using default (2000)\n");
         portno = 2000;
       }
     else 
       portno = atoi(argv[1]);
	
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     while (1) {
         newsockfd = accept(sockfd, 
               (struct sockaddr *) &cli_addr, &clilen);
         if (newsockfd < 0) 
             error("ERROR on accept");
         pid = fork();
         if (pid < 0)
             error("ERROR on fork");
         if (pid == 0)  {
             close(sockfd);
             dostuff(newsockfd);
             exit(0);
         }
         else close(newsockfd);
     } /* end of while */
     close(sockfd);
     return 0; /* we never get here */
}

/******** DOSTUFF() *********************
 There is a separate instance of this function 
 for each connection.  It handles all communication
 once a connnection has been established.
 *****************************************/
void dostuff (int sock)
{
   int n;
  
   int sensorMask_F3[]  = {10, 11, 12, 13, 14, 15,
			   0, 1, 2, 3, 4, 5, 6, 7}; 
   int sensorMask_FC6[] = {214, 215, 200, 201, 202, 203, 204, 
			   205, 206, 207, 192, 193, 194, 195}; 
   int sensorMask_P7[]  = {84, 85, 86, 87, 72, 73, 74, 
			   75, 76, 77, 78, 79, 64, 65};
   int sensorMask_T8[]  = {160, 161, 162, 163, 164, 165, 166, 
			   167, 152, 153, 154, 155, 156, 157};
   int sensorMask_F7[]  = {48, 49, 50, 51, 52, 53, 54, 
			   55, 40, 41, 42, 43, 44, 45};
   int sensorMask_F8[]  = {178, 179, 180, 181, 182, 183, 168,
			   169, 170, 171, 172, 173, 174, 175};
   int sensorMask_T7[]  = {66, 67, 68, 69, 70, 71, 56,
			   57, 58, 59, 60, 61, 62, 63};
   int sensorMask_P8[]  = {158, 159, 144, 145, 146, 147, 148, 
			   149, 150, 151, 136, 137, 138, 139};
   int sensorMask_AF4[] = {196, 197, 198, 199, 184, 185, 186, 
			   187, 188, 189, 190, 191, 176, 177};
   int sensorMask_F4[]  = {216, 217, 218, 219, 220, 221, 222,
			   223, 208, 209, 210, 211, 212, 213};
   int sensorMask_AF3[] = {46, 47, 32, 33, 34, 35, 36, 
			   37, 38, 39, 24, 25, 26, 27};
   int sensorMask_O2[]  = {140, 141, 142, 143, 128, 129, 130,
			   131, 132, 133, 134, 135, 120, 121};
   int sensorMask_O1[]  = {102, 103, 88, 89, 90, 91, 92, 
			   93 , 94 , 95, 80, 81, 82, 83};
   int sensorMask_FC5[] = {28, 29, 30, 31, 16, 17, 18,
			   19, 20, 21, 22, 23, 8, 9};

   deque<int> deque_F3(sensorMask_F3, 
		       sensorMask_F3 + sizeof(sensorMask_F3)/sizeof(int));
   deque<int> deque_FC6(sensorMask_FC6, 
			sensorMask_FC6 + sizeof(sensorMask_FC6)/sizeof(int));
   deque<int> deque_P7(sensorMask_P7, 
		       sensorMask_P7 + sizeof(sensorMask_P7)/sizeof(int));
   deque<int> deque_T8(sensorMask_T8, 
		       sensorMask_T8 + sizeof(sensorMask_T8)/sizeof(int));
   deque<int> deque_F7(sensorMask_F7, 
		       sensorMask_F7 + sizeof(sensorMask_F7)/sizeof(int));
   deque<int> deque_F8(sensorMask_F8, 
		       sensorMask_F8 + sizeof(sensorMask_F8)/sizeof(int));
   deque<int> deque_T7(sensorMask_T7, 
		       sensorMask_T7 + sizeof(sensorMask_T7)/sizeof(int));
   deque<int> deque_P8(sensorMask_P8, 
		       sensorMask_P8 + sizeof(sensorMask_P8)/sizeof(int));
   deque<int> deque_AF4(sensorMask_AF4, 
			sensorMask_AF4 + sizeof(sensorMask_AF4)/sizeof(int));
   deque<int> deque_F4(sensorMask_F4, 
		       sensorMask_F4 + sizeof(sensorMask_F4)/sizeof(int));
   deque<int> deque_AF3(sensorMask_AF3, 
			sensorMask_AF3 + sizeof(sensorMask_AF3)/sizeof(int));
   deque<int> deque_O2(sensorMask_O2, 
		       sensorMask_O2 + sizeof(sensorMask_O2)/sizeof(int));
   deque<int> deque_O1(sensorMask_O1, 
		       sensorMask_O1 + sizeof(sensorMask_O1)/sizeof(int));
   deque<int> deque_FC5(sensorMask_FC5, 
			sensorMask_FC5 + sizeof(sensorMask_FC5)/sizeof(int));

   map< string , deque<int> > SensorBits;
   SensorBits["F3"] = deque_F3;
   SensorBits["FC6"] = deque_FC6;
   SensorBits["P7"] = deque_P7;
   SensorBits["T8"] = deque_T8;
   SensorBits["F7"] = deque_F7;
   SensorBits["F8"] = deque_F8;
   SensorBits["T7"] = deque_T7;
   SensorBits["P8"] = deque_P8;
   SensorBits["AF4"] = deque_AF4;
   SensorBits["F4"] = deque_F4;
   SensorBits["AF3"] = deque_AF3;
   SensorBits["O2"] = deque_O2;
   SensorBits["O1"] = deque_O1;
   SensorBits["FC5"] = deque_FC5;

   unsigned char buffer[32];
   int decoded_data[14] = {0};
   int i = 0;
   uchar out[32];
   while(1)
     {   
       bzero(buffer,sizeof(buffer));
       n = read(sock,buffer,sizeof(buffer));
       if (n < 0) error("ERROR reading from socket");

       Decrypt32(buffer, out);
       
       int n = 0;
       for( map< string, deque<int> >::iterator ii = SensorBits.begin(); 
	    ii != SensorBits.end(); ++ii)
	 {
	   int level = 0;
	   for(int i = 13; i > -1; --i)
	     {
	       level <<= 1;
	       int b = (((*ii).second)[i] / 8 + 1), o = (((*ii).second)[i] % 8);
	       level |= ((out[b] >> o) & 1);
	     } 

	   decoded_data[n] = level;
	   cout << level << "\t";
	   //cout << level*0.51 << "\t";
	   ++n;
	 }
       cout << endl;       
    
       n = write(sock,decoded_data,sizeof(decoded_data));
       if (n < 0) error("ERROR writing to socket");
     }
}
