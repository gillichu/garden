(base) gc3045@COS-T0264KMR6R ~ % curl -X POST http://localhost:5001/sensor-data \
     -H "Content-Type: application/json" \
     -d '{"temperature": 25.4, "humidity": 60}'

{
  "message": "Data received successfully!"
}
