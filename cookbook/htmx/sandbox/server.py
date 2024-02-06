from random import randrange

from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/fetch', methods=['GET'])
def get():
    return str(randrange(100))

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
