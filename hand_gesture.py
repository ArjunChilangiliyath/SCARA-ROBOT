import cv2
import mediapipe as mp
import tkinter as tk
from tkinter import ttk
import serial
import time
import pyttsx3
import threading
import socket
from PIL import Image, ImageTk
from queue import Queue

# Initialize text-to-speech engine
engine = pyttsx3.init()
engine.setProperty('rate', 150)

speech_queue = Queue()
gui_queue = Queue()
servo_queue = Queue()

arduino = serial.Serial('/dev/ttyUSB1', 9600, timeout=1)
time.sleep(2)

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7)
mp_draw = mp.solutions.drawing_utils