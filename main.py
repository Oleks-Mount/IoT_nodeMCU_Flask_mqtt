from flask import Flask,render_template, request,redirect,url_for,flash,session
import paho.mqtt.client as mqtt

app = Flask(__name__)
app.config.from_object(__name__)

broker_address = "#"

client = mqtt.Client("P1")

client.connect(broker_address)

app.config.update(dict(
    DEBUG = True,
    SECRET_KEY = 'debelopment key'
))

app.config.from_envvar('FLASKR_SETTINGS', silent=True)



@app.route('/')
def show_form():
    return render_template('form.html')


@app.route('/add_data', methods = ['POST'])
def write_data():
    p2 = request.form['two']
    client.publish("inTopic", p2)
    flash('New post was successfully posted')
    return redirect(url_for('show_form'))


if __name__ == '__main__':
    app.run(debug=True)
