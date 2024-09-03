from random import randrange

from flask import Flask
from flask import request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/fake', methods=['GET'])
def fake():
    print(request.args)
    id = request.args.get("id", default=None, type=int)
    return f"ID is {id}"

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
