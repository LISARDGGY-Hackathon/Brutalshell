import os
import socket
import sys

SOCKET_PATH = "/tmp/brutalshell.sock"

def main():
    if os.path.exists(SOCKET_PATH):
        os.remove(SOCKET_PATH)

    server = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    server.bind(SOCKET_PATH)
    server.listen(1)
    
    print(f"Listening on {SOCKET_PATH}...")

    while True:
        try:
            conn, _ = server.accept()
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                # Print received data to stdout (which is what we want to see)
                sys.stdout.buffer.write(data)
                sys.stdout.flush()
            conn.close()
        except KeyboardInterrupt:
            break
        except Exception as e:
            print(f"Error: {e}")

    os.remove(SOCKET_PATH)

if __name__ == "__main__":
    main()
