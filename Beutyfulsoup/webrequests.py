from bs4 import BeautifulSoup
import requests

html_text = requests.get("https://www.timesjobs.com/candidate/job-search.html?searchType=personalizedSearch&from=submit&searchTextSrc=ft&searchTextText=&txtKeywords=python&txtLocation=").text

soup = BeautifulSoup(html_text, "lxml")

jobs = soup.find_all("li", class_="clearfix job-bx wht-shd-bx")
for job in jobs:
    day = job.find("span",class_="sim-posted").span.text
    if('few' in day):
        company_name = job.find("h3",class_="joblist-comp-name").text.replace(" ","")
        skills =job.find("span",class_="srp-skills").text.replace(" ","")
        each_skill = skills.replace(","," ").split()
        more_info = job.header.h2.a['href']
#print(company_name)
#print(skills)
#print(each_skill)
        print('company name = {}'.format(company_name.strip()))
        print("skills ={}".format(skills.strip()))
        print("link = {}".format(more_info.strip()))
        print()