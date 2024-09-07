from random import randrange

from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/models', methods=['GET'])
def models():
    response = """
    <option value='325i'>325i</option>
    <option value='325ix'>325ix</option>
    <option value='X5'>X5</option>
    """
    return response

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
