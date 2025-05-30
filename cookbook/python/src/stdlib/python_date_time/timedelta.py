from datetime import timedelta

def days_hours_minutes(duration):
    """
    Convert a timedelta object to days, hours, minutes
    https://stackoverflow.com/questions/2119472/convert-a-timedelta-to-days-hours-and-minutes
    """

    return duration.days, duration.seconds//3600, (duration.seconds//60)%60

def hours_minutes_seconds(duration):
    """
    Convert a timedelta object to hours, minutes, seconds
    https://stackoverflow.com/questions/14190045/how-do-i-convert-datetime-timedelta-to-minutes-hours-in-python
    """

    seconds = duration.total_seconds()
    hours = seconds // 3600
    minutes = (seconds % 3600) // 60
    seconds = seconds % 60

    return hours, minutes, seconds

if __name__ == '__main__':

    # delta = timedelta(
    #     weeks=2, 
    #     days=50,
    #     hours=8, 
    #     minutes=5, 
    #     seconds=27,
    #     milliseconds=29000, 
    #     microseconds=10)
    delta = timedelta(
        days=5, 
        minutes=1280)
    
    print(str(delta))
    days, hours, minutes = days_hours_minutes(delta)
    print(f'{days} days {hours}h {minutes}min')

    hours, minutes, seconds = hours_minutes_seconds(delta)
    print(f'{hours}h {minutes}min')