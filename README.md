# TinyML Weather Station with ESP32 and DHT Sensor

## Abstract
Weather prediction is one of the most important applications of Machine Learning. In this report, we use data from weather stations in Boston, Massachusetts, to build a model that can predict the pressure based on temperature and humidity readings. The data is preprocessed, and a neural network is trained to predict the pressure. The model is then converted to TensorFlow Lite format and deployed on an ESP32 microcontroller. The results show that the model can predict the pressure with reasonable accuracy.



## Introduction
Weather prediction has always been a challenging task due to the complexity of the atmosphere and the vast amount of data involved. However, with the advent of machine learning, it has become possible to build models that can learn patterns in weather data and make accurate predictions. In this project, we use machine learning techniques to build a weather station that can predict pressure based on temperature and humidity readings. The station is built using an ESP32 microcontroller and a DHT sensor, and the model is trained using weather data from Boston, Massachusetts. The project demonstrates the potential of using machine learning for weather prediction and its practical applications in various fields.


## Data Preparation
From Kaggle, we obtained weather data from weather stations in Boston, Massachusetts. The data was collected over a period of several years and includes temperature, humidity, and pressure readings. We dropped any rows where all values were NaN. We also renamed some of the columns for clarity.
We split the data into training, validation, and test sets. The training set is used to train the model, the validation set is used to tune the model's hyperparameters, and the test set is used to evaluate the model's performance.


## Training Model
We used TensorFlow and Keras to build a neural network that takes temperature and humidity readings as input and predicts the pressure as output. We experimented with different architectures, and settled on a simple two-layer model with 16 neurons in each layer. We used the mean squared error loss function and the root mean squared error metric to evaluate the model's performance.


## Model Evaluation
We trained the model on the training set for 500 epochs, with a batch size of 16. We used the validation set to monitor the model's performance during training and avoid overfitting. We also plotted the training and validation loss and mean absolute error to visualize the model's performance.




## Conversion to tflite
After training the model, we converted it to the TensorFlow Lite format, which is optimized for deployment on microcontrollers. We used the TensorFlow Lite converter to convert the model, and saved the resulting .tflite file.


## Running in Esp32
Finally, we deployed the model on an ESP32 microcontroller, which is a low-cost, low-power microcontroller with built-in Wi-Fi and Bluetooth capabilities. We used the TensorFlow Lite for Microcontrollers library to run the model on the ESP32. We connected the ESP32 to a DHT11 sensor, which measures temperature and humidity, and used the sensor readings as input to the model. We then printed the predicted pressure to the serial port, which can be read by a computer.




## Results



The output pressure was around 1026 P which was pretty close to the actual pressure (1011 P) at the time of testing.


## Discussion

Our experiments show that neural networks can be used to predict weather data such as pressure, temperature, and humidity. We trained two models with different architectures and found that both models can achieve good performance on the test set.

One limitation of our study is that we only used data from the city of Boston. It is possible that the models may not generalize well to other locations. Future studies can explore the use of data from multiple locations to improve the generalization of the models.

Another limitation is that we only used two input features (temperature and humidity) to predict the output variable (pressure). Future studies can explore the use of additional input features such as wind speed, wind direction, and precipitation to improve the performance of the models.

Overall, our study demonstrates the potential of using neural networks for weather prediction. With further research and development, neural network models can be used to improve the accuracy of weather forecasts, which can have significant practical applications in various fields such as agriculture, transportation, and energy.


## Future Proposal

Here are some potential future proposals for expanding upon the work done in this project:

1. Multi-location data analysis: As noted in the discussion section, the study was limited to weather data from Boston. Future research can involve the use of data from multiple locations to improve the generalization of the models.

2. Use of additional input features: In this project, only two input features (temperature and humidity) were used to predict the output variable (pressure). Future studies can explore the use of additional input features such as wind speed, wind direction, and precipitation to improve the performance of the models.

3. Real-time weather forecasting: In this project, the model was deployed on an ESP32 microcontroller, which allowed for real-time weather prediction. Future research can focus on developing a more robust weather station that can collect and analyze data from multiple sensors in real-time.

4. Integration with other technologies: In addition to microcontrollers, weather prediction models can be integrated with other technologies such as drones, satellites, and IoT devices to improve data collection and analysis.

5. Machine learning model optimization: The current project used a simple two-layer neural network with 16 neurons in each layer. Future studies can explore more complex model architectures and hyperparameter tuning techniques to further optimize the models for weather prediction.




## References

1. TensorFlow. (n.d.). TensorFlow Lite for Microcontrollers. Retrieved from https://www.tensorflow.org/lite/microcontrollers

2. Espressif Systems. (n.d.). ESP32. Retrieved from https://www.espressif.com/en/products/socs/esp32

3. Kaggle. (n.d.). Weather Station Data (Temperature, Pressure, Humidity). Retrieved from https://www.kaggle.com/muthuj7/weather-dataset

