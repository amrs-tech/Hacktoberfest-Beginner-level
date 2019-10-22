# make sure to have selenium downloaded
# as well as Geckodriver and Mozilla Firefox
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

#create the class where we pass our email and password for the bot to use to log in
class TwitterBot:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        self.bot = webdriver.Firefox()

# login function, sleep gives time for pages to load
#bot uses firefox to go to twitter and login
    def login(self):
        bot = self.bot
        bot.get('https://twitter.com/')
        time.sleep(3)
        email = bot.find_element_by_class_name('email-input') #finds the field to enter username
        password = bot.find_element_by_name('session[password]') #finds the field to enter password
        email.clear()
        password.clear()
        email.send_keys(self.username) #bot enteres email
        password.send_keys(self.password) #bot enteres password
        password.submit() #bot submits the email/password
        time.sleep(3)

#this function enters a given hashtag to search and begins liking them by finding
#the html element with the class name of HeartAnimation
    def like_tweets(self, hashtag):
        bot = self.bot
        bot.get('https://twitter.com/search?q=' + hashtag + '&src=typd')
        time.sleep(3)
        for i in range(1,3):
            bot.execute_script('window.scrollTo(0, document.body.scrollHeight)')
            time.sleep(2)
            tweets = bot.find_elements_by_class_name('tweet')
            links = [elem.get_attribute('data-permalink-path') for elem in tweets]
            for link in links:
                bot.get('https://twitter.com' + link)
                try:
                    bot.find_element_by_class_name('HeartAnimation').click()
                    time.sleep(15)
                except Exception as ex:
                    time.sleep(30)

#make sure to use your own email and password for your twitter account
drew = TwitterBot('EMAIL_ADDRESS_HERE', 'PASSWORD_HERE')
drew.login()
drew.like_tweets('pythonprogramming')
