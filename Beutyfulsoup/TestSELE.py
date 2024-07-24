from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

options = webdriver.ChromeOptions()
options.add_experimental_option("detach", True)
driver = webdriver.Chrome(executable_path="C:\\Users\\BB\\Desktop\\Selenium\\chromedriver-win64\\chromedriver.exe", options=options)

driver.get("https://www.google.com/")
btn_login = driver.find_element(By.CSS_SELECTOR, 'a[href^="https://accounts.google.com/ServiceLogin?hl=th&passive=true&continue=https://www.google.com/&ec=GAZAmgQ"]')
btn_login.click()

# Wait for the username input field to be present
wait = WebDriverWait(driver, 10)

fill_login = wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'input[type="email"]')))

# Type 'Hello' into the input field
fill_login.send_keys("bigza3838@gmail.com")
