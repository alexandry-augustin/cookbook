from random import randrange

from flask import Flask
from flask import Response
from flask import request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/trigger_custom_event', methods=['GET'])
def trigger_custom_event():

    content = """
        <div style="margin-bottom: 100px;">Notification Sent</div>
    """
    response = Response(content)
    response.headers['HX-Trigger'] = 'my_event'
    # response.headers['HX-Trigger'] = '{"my_event":"Here Is A Message"}'
    print(response.headers)

    return response

@app.route('/update_element_one', methods=['GET'])
def update_element_one():
    return """<div>New Element One</div>"""

@app.route('/update_element_two', methods=['GET'])
def update_element_two():
    return """<div>New Element Two</div>"""

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
