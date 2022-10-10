#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>
#include <libpq-fe.h>  
#include <string>
#include <codecvt>
#include <locale>
using namespace std;
void do_exit(PGconn *conn) {

	PQfinish(conn);
	exit(1);
}
const string showU8Str(const string &str) {
	std::string u8str;
	wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
	for (int i = 0; i < str.length(); ) {
		cout << str.substr(i, 4) << endl;
		unsigned int uhan = strtol(str.substr(i, 4).c_str(), nullptr, 16);
		u8str += converter.to_bytes(uhan);

		i += 4;
	}

	return u8str;
}
int main() {
	//�������ݿ�,�����ַ���
	PGconn *conn = PQconnectdb("user=postgres dbname=shop password=990510");
	//����������Ϣ
	if (PQstatus(conn) == CONNECTION_BAD) {

		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		cout << "shibai";
		do_exit(conn);
	}
	else {
		cout << "�ɹ�"<<endl;
	}
	//��ȡ���ݱ���
	PGresult *res = PQexec(conn, "SELECT * FROM Product");

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {

		printf("No data retrieved\n");
		PQclear(res);
		do_exit(conn);
	}
	//����ѯ������
	int rows = PQntuples(res);

	for (int i = 0; i < rows; i++) {
		auto x1 = PQgetvalue(res, i, 0);
		auto x2= PQgetvalue(res, i, 1);
		auto x3= PQgetvalue(res, i, 4);
		cout << showU8Str(PQgetvalue(res, i, 1)) << "  " << x2 << "  " << x3 << endl;
	}

	PQclear(res);
	PQfinish(conn);

	system("pause");
}