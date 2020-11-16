#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
	if( argc == 2){		//read from input, write to file1
		int output_fd= open(argv[1], O_WRONLY |O_CREATE);	//open file named arg[0]
		if (output_fd <0)
		 {
			printf(1, "fd problem \n");
			return -1;
		 }
		char buf[100];
		write(1, "1 arg, please enter text:\n",27);
		read(0,&buf,sizeof(buf));
		write(output_fd, buf,sizeof(buf));
		write(1, buf,sizeof(buf));
		write(1, "\n",2);

	}
	else if( argc == 3 ){	//read from file1, write to file2
		int output_fd= open(argv[2], O_WRONLY |O_CREATE);	//open file named arg[1]
		int input_fd= open(argv[1], O_RDONLY);	//open file named arg[2]
		if (output_fd <0)
		 {
			printf(1, "fd problem \n");
			return -1;
		 }
		if (input_fd <0)
		 {
			printf(1, "fd problem \n");
			return -1;
		 }

		char buf[100];
		read(input_fd,&buf,sizeof(buf));
		write(output_fd, buf,sizeof(buf));
		write(1, "2 args, we copied this:\n",25);
		write(1, buf,sizeof(buf));
		write(1, "\n",2);

		
	}

	else {
		printf(1, "wrong input for tee\n");

		return -1;
	}
	
// int i;
 // for(i = 1; i < argc; i++)
 //   printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");
  //exit(0);
}
