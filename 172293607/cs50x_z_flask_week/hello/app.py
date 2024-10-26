from flask import Flask, render_template, request

app = Flask(__name__)   #refer to the current file name

@app.route("/", methods=["GET", "POST"]) #/ means default
def index():
    if request.method == "POST":
        name = request.form.get("name")
        return render_template("greet.html", a_placeholder = name)
    return render_template("index.html")



