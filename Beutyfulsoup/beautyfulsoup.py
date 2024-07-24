from bs4 import BeautifulSoup

with open("home.html", "r") as html_file:
    content = html_file.read()
    #print(content)

    soup = BeautifulSoup(content, 'lxml')
    #print(soup.prettify())

    # course_html_tags = soup.find_all("h5",)
    # for course in course_html_tags:
    #     print(course.text)

    course_card = soup.find_all("div", class_="card")
    for course in course_card:
        course_name = course.h5.text
        course_price = course.a.text.split()[-1]
        print("{} {} {}".format(course_name,int(course_price[:-1])*36,"Bath"))
