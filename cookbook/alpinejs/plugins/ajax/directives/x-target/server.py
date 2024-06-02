from flask import Flask
from flask import request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/comment', methods=['POST'])
def comment():
    comment = request.form['text']
    print(comment)
    return f""" 
    <ul id="comments">
		<li>{comment}</li>
	</ul>"""

if __name__ == '__main__':

    app.run(host='0.0.0.0', port=8000, debug=True)
