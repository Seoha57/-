/**************************************
Ʈ�� ��ȸ
�ð� ����   �޸� ����
   2 ��        128 MB

����
���� Ʈ���� �Է¹޾� ���� ��ȸ(preorder traversal), ���� ��ȸ(inorder traversal), ���� ��ȸ(postorder traversal)�� ����� 
����ϴ� ���α׷��� �ۼ��Ͻÿ�.


���� ��� ���� ���� ���� Ʈ���� �ԷµǸ�,
���� ��ȸ�� ��� : ABDCEFG // (��Ʈ) (���� �ڽ�) (������ �ڽ�)
���� ��ȸ�� ��� : DBAECFG // (���� �ڽ�) (��Ʈ) (������ �ڽ�)
���� ��ȸ�� ��� : DBEGFCA // (���� �ڽ�) (������ �ڽ�) (��Ʈ)
�� �ȴ�.

�Է�
ù° �ٿ��� ���� Ʈ���� ����� ���� N(1��N��26)�� �־�����. 
��° �ٺ��� N���� �ٿ� ���� �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ��尡 �־�����. 
����� �̸��� A���� ���ʴ�� ������ �빮�ڷ� �Ű�����, �׻� A�� ��Ʈ ��尡 �ȴ�. �ڽ� ��尡 ���� ��쿡�� .���� ǥ���ȴ�.

���
ù° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ�� ����� ����Ѵ�. 
�� �ٿ� N���� ���ĺ��� ���� ���� ����ϸ� �ȴ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	char pLeft;
	char pRight;
};

void preorder(const vector<Node>& n, char r) {
	if (r == '.')
		return;

	int rNum = r - 'A';
	cout << r;
	preorder(n, n[rNum].pLeft);
	preorder(n, n[rNum].pRight);
}

void inorder(const vector<Node>& n, char r) {
	if (r == '.')
		return;

	int rNum = r - 'A';
	inorder(n, n[rNum].pLeft);
	cout << r;
	inorder(n, n[rNum].pRight);
}

void postorder(const vector<Node>& n, char r) {
	if (r == '.')
		return;

	int rNum = r - 'A';
	postorder(n, n[rNum].pLeft);
	postorder(n, n[rNum].pRight);
	cout << r;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<Node> table(n);
	for (int i = 0; i < n; ++i) {
		char p, l, r;
		cin >> p >> l >> r;

		int nodeNum = p - 'A';
		table[nodeNum].pLeft = l;
		table[nodeNum].pRight = r;
	}
	preorder(table, 'A');
	cout << '\n';
	inorder(table, 'A');
	cout << '\n';
	postorder(table, 'A');
	cout << '\n';

	return 0;
}