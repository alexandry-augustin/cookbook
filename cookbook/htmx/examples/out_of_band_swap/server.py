from random import randrange

from flask import Flask
from flask import request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/hx_swap_oob', methods=['GET'])
def hx_swap_oob():

    # NOTE 1: These oob elements must be in the top level of the response, and not a children of an element.

    # NOTE 2: 
    # htmx will use the main content to perform the swap of the HTML element that did the call to the server. 
    # After that, it will use any additional HTML marked with `hx-swap-oob="true"`
    # and swap that with the HTML already on the page, given the `id` matches.

    return """
        <!-- Main Content -->
        <div>
            New Button Label
        </div>

        <!-- OOB Content -->
		<div id="element-one" hx-swap-oob="innerHTML">New Element One</div>
		<div id="element-two" hx-swap-oob="innerHTML">New Element Two</div>
    """

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
