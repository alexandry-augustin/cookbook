import os

from dotenv import load_dotenv
from dotenv import dotenv_values

def test_00():
    #from pathlib import Path

    #dotenv_path = Path('path/to/.env')
    #load_dotenv(dotenv_path=dotenv_path)

    load_dotenv()

    ACCESS_TOKEN = os.getenv("ACCESS_TOKEN")
    assert(ACCESS_TOKEN == "ABC123")

def test_01():
    config = dotenv_values('.env')
    assert(config['ACCESS_TOKEN'] == "ABC123")

if __name__ == '__main__':

    test_00()
    test_01()
