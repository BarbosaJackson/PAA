#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef struct _post post;
typedef vector<post> vp;
typedef pair<double, string> pds;
typedef vector<pds> vpds;

struct _post {
	int id_friend;
	double proximity, time_update;
	vpds post_friend;
};

int search(vp posts, int id, int start, int end) {
	int mid = (start + end) / 2;
	if(id == posts[mid].id_friend) return mid;
	else if(id > posts[mid].id_friend) return search(posts, id, mid + 1, end);
	else return search(posts, id, start, mid);
}

int main() {
	int n, m, x;
	vp posts;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		post p;
		cin >> p.id_friend >> p.proximity;
		posts.pb(p);
	}
	sort(posts.begin(), posts.end(), []( const _post &left, const _post &right ){ return left.id_friend < right.id_friend;});
	cin >> x;
	for(int i = 0; i < x; i++) {
		int id_friend;
		string text_post;
		double time_update;
		cin >> id_friend >> time_update;
		getline(cin, text_post);
		int pos = search(posts, id_friend, 0, (int)posts.size());
		posts[pos].post_friend.pb(mp(time_update, text_post));
	}
	return 0;
}