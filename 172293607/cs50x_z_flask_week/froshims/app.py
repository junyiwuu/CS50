from flask import Flask, render_template, request

app = Flask(__name__)   #refer to the current file name

SPORTS = ["basketball", "soccer", "ultimate", "a", "b"]

@app.route("/") #/ means default
def index():
    return render_template("index.html", sports=SPORTS)



@app.route("/register", methods=["POST"])
def register():
    if not request.form.get("name"):
        return render_template("failure.html")

    for sport in request.form.getlist("sport"):
        if sport not in SPORTS:
            return render_template("failure.html")
    return render_template("success.html")