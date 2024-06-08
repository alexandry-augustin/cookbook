from random import randrange

from flask import Flask
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/sidebar', methods=['GET'])
def sidebar():
    print("SENT")
    return "Body..."
    #return """
    #    <div class="offcanvas-body">
    #        Body...
    #    </div>
    #"""
if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
