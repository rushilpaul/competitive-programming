#!/usr/bin/python
url = 'http://www.easypolls.net/poll?jsoncallback=jQuery1102043759123584718296_1436987933237&command=getPoll&pollId=55a63191e4b06ca1d511fd0e&isMobile=false&_=1436987933238'

import mechanize, cookielib, json, time
from random import randint
br = mechanize.Browser()
cj = cookielib.LWPCookieJar()
br.set_cookiejar(cj)

# Browser options
br.set_handle_equiv(True)
br.set_handle_redirect(True)
br.set_handle_referer(True)
br.set_handle_robots(False)

br.set_handle_refresh(mechanize._http.HTTPRefreshProcessor(), max_time=1)
br.addheaders = [ ('Host','www.easypolls.net'), ('User-Agent','Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:38.0) Gecko/20100101 Firefox/38.0'), ('Accept','text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'), ('Accept','text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'), ('Accept-Language','en-US,en;q=0.5'), ('Accept-Encoding','deflate') ]

count = 1

while True:
	cj.clear()
	res = br.open(url)
	page = res.read()
	search = 'pollKey":"'
	pos = page.find(search) + len(search)
	pkey = page[pos:pos+7]

	submit = 'http://www.easypolls.net/poll?jsoncallback=jQuery1102048485376518992906_143698468448%s&multResp2=2&pollId=55a63191e4b06ca1d511fd0e&pollKey=%s&command=saveResponse&_=1436984684490' % (str(randint(1,9)),pkey)

	res = br.open(submit)
	page = res.read()
	page = page[ page.find('{') : page.rfind('}')+1 ]
	data = json.loads(page)
	if data['resultCode'] == '0':
		print 'Successful:', count
		count += 1
	else:
		print 'Unsuccessful'
	#time.sleep(2)
