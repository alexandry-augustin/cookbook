from time import sleep

from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/wait', methods=['GET'])
def wait():
    sleep(5)
    return "Done"

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
