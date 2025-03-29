from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/", methods=["GET"])
def home():
    return "Flask Server is Running!"

@app.route("/sensor-data", methods=["POST"])
def receive_data():
    data = request.json  # Get JSON data from the request
    print(f"Received data: {data}")
    return jsonify({"message": "Data received successfully!"}), 200


if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0", port=5001)
