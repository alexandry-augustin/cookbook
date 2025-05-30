import time
import signal

# https://stackoverflow.com/questions/492519/timeout-on-a-function-call

def loop_forever():

    while True:
        print('.')
        time.sleep(1)

def handler(signum, frame):
    """Register an handler for the timeout"""

    raise Exception("Timeout Exception")

if __name__ == '__main__':

    # Register the signal function handler
    signal.signal(signal.SIGALRM, handler)

    # Set a timeout
    signal.alarm(5)

    try:
        loop_forever()
    except Exception as e: 
        print(e)

    # Cancel the timer if the function returned before timeout
    # signal.alarm(0)