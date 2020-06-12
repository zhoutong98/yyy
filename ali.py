
# -*- coding:utf-8 -*-

from aliyunsdkcore.client import AcsClient
#from aliyunsdkcore.acs_exception.exceptions import ClientException
#from aliyunsdkcore.acs_exception.exceptions import ServerException
from aliyunsdkecs.request.v20140526.DescribeRegionsRequest import DescribeRegionsRequest

client = AcsClient('LTAI4GF8r7PwYeTFhp9ZzYGu', 'LhQRiEM3MDpUC1kZ5PUaKncpTAuwBE', 'cn-hangzhou')

request = DescribeRegionsRequest()
request.set_accept_format('json')

response = client.do_action_with_exception(request)

print(str(response, encoding='utf-8'))