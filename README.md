# MOST UPDATED built web server from scratch project-
README 

This project was a great way for me to learn more about C and how servers work.
The code sets up a basic web server using low level socket functions, so I can actually see how data moves across the internet. By creating a socket, binding it to a port, and accepting connections


deeper understanding: 

It’s built on raw sockets no frameworks, no shortcuts. This project is a lightweight HTTP server written entirely in C using raw TCP sockets. It sets up a listening socket, waits for incoming client connections, prints the incoming HTTP request, and sends back a basic HTML response.

How to Run This Web Server:

Clone or Download the Project

git clone https://github.com/codefor4fun888/web-server.git
cd web-server

Or download ZIP:

Click Code - > Download ZIP

Extract the folder

Open the extracted directory

Your folder should contain:

server.c
server.h
test.c
main.c

2. Open a Terminal in the Project Directory
Windows (PowerShell):
cd "path\to\web-server"

macOS / Linux:
cd path/to/web-server

3. Compile the Server
Windows (MinGW / TDM-GCC)

You must link the Winsock library:

gcc server.c test.c main.c -lws2_32 -o server.exe

macOS / Linux
gcc server.c test.c main.c -o server


If the command prints no errors, compilation succeeded.

4. Run the Server
Windows
.\server.exe

macOS / Linux
./server


You should now see:

====== SERVER RUNNING (CTRL+C to stop) ======
====== WAITING FOR CONNECTION ======

5. Open the Server in Your Browser

Navigate to:

http://localhost:8080


Or port 80 if you changed the port number in the code.

You’ll see the HTML response:

Mono Deus — Server Alive!!!

6. Stop the Server

Press:

CTRL + C
