#include <winsock.h>
#include <iostream>
#include <string>
#include <mysql.h>
using namespace std;

#define STEPBYSTEP
int main() {
cout << "****************************************" << endl;
#ifdef STEPBYSTEP
system("pause");
#endif
MYSQL mydata;
if (0 == mysql_library_init(0, NULL, NULL)) {
cout << "mysql_library_init() succeed" << endl;
}
else {
cout << "mysql_library_init() failed" << endl;
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
if (NULL != mysql_init(&mydata)) {
cout << "mysql_init() succeed" << endl;
}
else {
cout << "mysql_init() failed" << endl;
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
cout << "mysql_options() succeed" << endl;
}
else {
cout << "mysql_options() failed" << endl;
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
if (NULL
!= mysql_real_connect(&mydata, "localhost", "root", "zhoutong98", "zt", 3306, NULL, 0))
{
cout << "mysql_real_connect() succeed" << endl;
}
else {
cout << "mysql_real_connect() failed" << endl;
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
string sqlstr;
sqlstr = "CREATE TABLE IF NOT EXISTS user_info";
sqlstr += "(";
sqlstr +=
"user_id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY COMMENT 'Unique User ID',";
sqlstr +=
"user_name VARCHAR(100) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL COMMENT 'Name Of User',";
sqlstr +=
"user_second_sum INT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'The Summation Of Using Time'";
sqlstr += ");";
if (0 == mysql_query(&mydata, sqlstr.c_str())) {
cout << "mysql_query() create table succeed" << endl;
}
else {
cout << "mysql_query() create table failed" << endl;
mysql_close(&mydata);
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
sqlstr =
"INSERT INTO user_info(user_name) VALUES('公司名称'),('一级部门'),('二级部门'),('开发小组'),('姓名');";
if (0 == mysql_query(&mydata, sqlstr.c_str())) {
cout << "mysql_query() insert data succeed" << endl;
}
else {
cout << "mysql_query() insert data failed" << endl;
mysql_close(&mydata);
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
sqlstr = "SELECT user_id,user_name,user_second_sum FROM user_info";
MYSQL_RES *result = NULL;
if (0 == mysql_query(&mydata, sqlstr.c_str())) {
cout << "mysql_query() select data succeed" << endl;
result = mysql_store_result(&mydata);
int rowcount =(int) mysql_num_rows(result);
cout << "row count: " << rowcount << endl;
unsigned int fieldcount = mysql_num_fields(result);
MYSQL_FIELD *field = NULL;
for (unsigned int i = 0; i < fieldcount; i++) {
field = mysql_fetch_field_direct(result, i);
cout << field->name << "\t\t";
}
cout << endl;
MYSQL_ROW row = NULL;
row = mysql_fetch_row(result);
while (NULL != row) {
for (unsigned int i = 0; i < fieldcount; i++) {
cout << row[i] << "\t\t";
}
cout << endl;
row = mysql_fetch_row(result);
}
}
else {
cout << "mysql_query() select data failed" << endl;
mysql_close(&mydata);
return -1;
}
#ifdef STEPBYSTEP
system("pause");
#endif
sqlstr = "DROP TABLE user_info";
if (0 == mysql_query(&mydata, sqlstr.c_str())) {
cout << "mysql_query() drop table succeed" << endl;
}
else {
cout << "mysql_query() drop table failed" << endl;
mysql_close(&mydata);
return -1;
}
mysql_free_result(result);
mysql_close(&mydata);
mysql_server_end();
system("pause");
return 0;
}