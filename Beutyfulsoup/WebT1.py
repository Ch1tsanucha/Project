from bs4 import BeautifulSoup
import requests
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from time import sleep
import pandas as pd

# Get the HTML content from the URL
#response = requests.get("https://www.mcdonalds.com/de/de-de/restaurant-suche.html/l/berlin").text
driver = webdriver.Chrome()
driver.get("https://www.mcdonalds.com/de/de-de/restaurant-suche.html/l/berlin")
sleep(7)
page = driver.page_source
# print(page)
soup = BeautifulSoup(page, "lxml")
box = soup.find("ul", class_="ubsf_sitemap-list")
box2 = box.find_all("li")
# print(box)
driver.close()

First = []
for position in box2:
    address = position.find('div', class_="ubsf_sitemap-location-address")
    print('{}'.format(address.text))
    First.append(address.text.split(',')[0])

# print(First)

# df = pd.DataFrame(data = array,  
#                   index = index_values,  
#                   columns = column_values) 
  
column_values = ["Address"]
df = pd.DataFrame(data = First,
                  columns=column_values)
print(df)