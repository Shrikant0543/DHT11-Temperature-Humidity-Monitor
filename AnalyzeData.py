
from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt

# ---------- FILE SETUP ----------

project_folder = Path(__file__).resolve().parent

# Load Arduino measurements
csv_file = project_folder / "sample_data(1).csv"
data = pd.read_csv(csv_file)

# Convert milliseconds to minutes
data["Time_minutes"] = data["Time_ms"] / 60000

# ---------- DATA STATISTICS ----------

print("DHT11 Sensor Data Analysis")
print("-------------------------")
print(f"Total readings: {len(data)}")

# Fahrenheit temperature statistics
print("\nTemperature (Fahrenheit)")
print(f"Average: {data['Temperature_F'].mean():.2f} F")
print(f"Minimum: {data['Temperature_F'].min():.2f} F")
print(f"Maximum: {data['Temperature_F'].max():.2f} F")

# Humidity statistics
print("\nRelative Humidity")
print(f"Average: {data['Humidity'].mean():.2f}%")
print(f"Minimum: {data['Humidity'].min():.2f}%")
print(f"Maximum: {data['Humidity'].max():.2f}%")

# ---------- GRAPH SETUP ----------

images_folder = project_folder / "images"
images_folder.mkdir(exist_ok=True)

# ---------- TEMPERATURE GRAPH ----------

plt.figure(figsize=(10, 5))

plt.plot(
    data["Time_minutes"],
    data["Temperature_F"],
    color="red",
    linewidth=2
)

plt.title("DHT11 Temperature Over Time")
plt.xlabel("Time (minutes)")
plt.ylabel("Temperature (Fahrenheit)")
plt.grid(True)
plt.tight_layout()

plt.savefig(images_folder / "temperature_graph.png", dpi=300)
plt.close()

# ---------- HUMIDITY GRAPH ----------

plt.figure(figsize=(10, 5))

plt.plot(
    data["Time_minutes"],
    data["Humidity"],
    color="blue",
    linewidth=2
)

plt.title("DHT11 Humidity Over Time")
plt.xlabel("Time (minutes)")
plt.ylabel("Relative Humidity (%)")
plt.grid(True)
plt.tight_layout()

plt.savefig(images_folder / "humidity_graph.png", dpi=300)
plt.close()

# ---------- FINISHED ----------

print("\nBoth graphs saved successfully!")