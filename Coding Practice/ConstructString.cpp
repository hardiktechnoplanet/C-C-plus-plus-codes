//#include<bits/stdc++.h>
#include <stdint.h>

using namespace std;

void print(unsigned char output_string[])
{
	//cout<<"the output string is:"<<endl;
	//for(size_t i=0;i<sizeof(output_string);++i)
	//cout<<int(output_string[i])<<endl;
}

void constructString(uint8_t first, uint16_t second, unsigned char output_string[])
{
   stringstream stream;
   
   // process 'first'
   //convert unsigned int to string
   stream << hex << unsigned(first);
   string temp_string( stream.str() );
   
   //covert to uppercase
   transform(temp_string.begin(), temp_string.end(), temp_string.begin(), ::toupper);
   
   //store the temp_string in the output_string
   output_string[0]=temp_string[0];
   output_string[1]=temp_string[1];
   
   //clear the stringstream
   stream.str("");
	
   //convert second to string
   stream << std::hex << second;
   temp_string=stream.str();
    
   //change to upper case (this step is for consistency
   // as stored value 'C' is in upper case)
   transform(temp_string.begin(), temp_string.end(), temp_string.begin(), ::toupper);
	
   //store the temp_string in the output_string
   //store the MSB
   output_string[2]=(temp_string[0]);
   output_string[3]=(temp_string[1]);
	
   //call the print function
   print(output_string);
}
int main()
{
	uint16_t sensor_reading = 53672;
	uint8_t first = 0xC3;
	uint16_t second = sensor_reading;
	
	//output string
	unsigned char output_string[4];
	constructString(first,second,output_string);
	return 0;
}
