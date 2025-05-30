from datetime import datetime
from pytz import timezone

if __name__ == '__main__':

    time_zone = timezone('Europe/Stockholm')
    print(datetime.now(time_zone).isoformat())
