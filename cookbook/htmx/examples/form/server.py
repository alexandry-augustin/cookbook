from random import randrange

from flask import Flask
from flask import request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/form', methods=['POST'])
def form():
    print(request.args)
    return "Submitted"

@app.route('/form/email', methods=['POST'])
def validate_email():
    print(request.args)
    return "Validated"

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
