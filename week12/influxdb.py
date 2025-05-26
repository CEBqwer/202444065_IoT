# 라즈베리파이에서 아두이노(미세먼지센서) 사용해 influxDB로 데이터 전송

import time
import requests, json
from influxdb import InfluxDBClient as influxdb
import serial

seri = serial.Serial('/dec/ttyACM0', baudrate = 9600, timeout = None)

while(True):
  time.sleep(1)
  if seri.in_waiting != 0:
    content = seri.readline()
    a = float(content.decode())
    data = [{
      'measurement' : 'dust',
      'tags' : {
        'inhaUni':'2222',
        },
      'fields':{
        'dust' : a,
        }
    }]
    client = None
    try:
      client = influxdb('localhost',8086,'root','root','dust')
    except Exception as e:
      print("Exception" + str(e))
    if client is not None:
      try:
        client.write_points(data)
      except Exception as e:
        print("Exception" + str(e))
      finally:
        client.close()
    print(a)
    print("running influxdb OK")
