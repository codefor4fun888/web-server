# MOST UPDATED built web server from scratch project-
README 

This project was a great way for me to learn more about C and how servers work.
The code sets up a basic web server using low level socket functions, so I can actually see how data moves across the internet. By creating a socket, binding it to a port, and accepting connections


deeper understanding: 

It’s built on raw sockets no frameworks, no shortcuts. This project is a lightweight HTTP server written entirely in C using raw TCP sockets. It sets up a listening socket, waits for incoming client connections, prints the incoming HTTP request, and sends back a basic HTML response.


Clone or Download the Project
git clone https://github.com/yourusername/your-repo-name.git


Or download the ZIP and extract it.

Make sure the folder contains:

server.c
server.h
test.c
main.c

Open a Terminal in the Project Directory

On Windows (PowerShell):

cd "path\to\the\project"

On macOS/Linux:

cd path/to/the/project

Compile the Server -
Windows (MinGW or TDM-GCC)

You must link against the Winsock library:

gcc server.c test.c main.c -lws2_32 -o server.exe

Linux / macOS
gcc server.c test.c main.c -o server


If the command runs without errors, compilation succeeded!

Run the Server
Windows
.\server.exe

Linux / macOS
./server


You should see:

====== SERVER RUNNING (CTRL+C to stop) ======
====== WAITING FOR CONNECTION ======

Open in Your Browser

Navigate to:

http://localhost:8080


(Or port 80 if you changed it.)

You will see the HTML response:

Mono Deus — Server Alive!!!

to stop the Server

Press:

CTRL + C
