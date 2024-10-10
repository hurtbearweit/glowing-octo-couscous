# 物理实验上级报告
## 上级目的：  
1.熟悉Python的基本语法和编程环境。  
2.学习如何使用Python进行简单的数据处理和文件操作。  
3.掌握爬虫技能。

## 上机环境：

- 操作系统：Windows
- Python版本：Python 3.11
- 开发环境：PyCharm

## 上机要求：  
用Python编写爬虫，爬取百度新闻网页的新闻，尽可能详细（新闻时间、标题、分类、URL等）的保存到一个pdf(或其他格式)文件中

## 爬取网页：
网页[中国日报](https://china.chinadaily.com.cn/5bd5639ca3101a87ca8ff636)

## 爬取内容：
10月6日截至下午三点的新闻

## 代码部分:
```python
from bs4 import BeautifulSoup
import requests
import pandas as pd

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36"}
response = requests.get("https://china.chinadaily.com.cn/5bd5639ca3101a87ca8ff636", headers=headers)
html = response.text
soup = BeautifulSoup(html, "lxml")
divs = soup.find_all("div", class_="busBox3")
data = []
for div in divs:
    data_temp = {}
    title = div.find('h3').text
    date = div.find('b').text
    link_tag = div.find_all('a')
    if link_tag:
        link = link_tag[0]['href']  # 获取链接
    else:
        link = "No link found"  # 如果没有找到链接，则设置一个默认值
    data_temp['标题'] = title
    data_temp['时间'] = date
    data_temp['URL'] = link
    data.append(data_temp)
#至此已经完成了基本的爬虫任务，接下来来需要的就是进行把信息保存到excel中
df = pd.DataFrame(data)
df.to_excel('中国日报爬虫.xlsx')
print('保存成功')

```
## 实验结果与分析
最终得到的实验结果保存于中国日报爬虫.xlsx文件以及中国日报爬虫.pdf中，具体可见文件夹中的详细记录

## 实验总结
本次上机实验中，我学习了python爬虫技术，首先了解到了http传输协议的相关知识，随后又了解到了html文件的基本语法以及编写方法，最后学习了使用request库获取网页内容，还学会了用Beautifulsoup库对数据进行筛选，然后用pandas库将获取的内容存储于中国日报爬虫.xlsx，之后我又将中国日报爬虫.xlsx转为了中国日报爬虫.pdf文件。

## 爬虫缺点：
并没有爬取出每条新闻的类型，因为首页的新闻网太过于简略，虽然有每个板块（就是对应的类型），但是只有一个标题，并没有显示时间，而想要有时间信息，就要进入某一个板块中爬取（例如我爬取的就是中国日报的时政要闻部分），但是进入其中后内息那个就定下来了，本来想尝试多线程爬取，后来实在是麻烦，只得放弃，使用就留下了这么一个问题（也可能这个问题可以解决，但是我没有发现解决方法）。

