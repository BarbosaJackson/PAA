#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef struct _post post;
typedef vector<post> vp;
typedef pair<double, string> pds;
typedef pair<double, int> pdi;
typedef pair<pdi, string> pdis;
typedef vector<pdis> vpdis;
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
	vpdis view_posts(n);
	int count = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < (int)posts[i].post_friend.size(); j++) {
			double lvl = (0.8 * posts[i].proximity) + (0.2 * posts[i].post_friend[j].first);
			if(count < n) {
				view_posts[count].first.first = lvl;
				view_posts[count].first.second = posts[i].id_friend;
				view_posts[count].second = posts[i].post_friend[j].second;
				count++;
			} else {
				sort(view_posts.begin(), view_posts.end(), []( const pdis &a, const pdis &b) { return a.first.first < b.first.first; });
				for(int k = 0; k < n; k++) {
					if(view_posts[k].first.first < lvl) {
						view_posts[k].first.first = lvl;
						view_posts[k].first.second = posts[i].id_friend;
						view_posts[k].second = posts[i].post_friend[j].second;
						break;
					}
				}
			}
		}
	}
	sort(view_posts.begin(), view_posts.end(), []( const pdis &a, const pdis &b) { return a.first.first < b.first.first; });
	for(int i = n - 1; i >= 0; i--) {
		cout << view_posts[i].first.second << view_posts[i].second << endl;
	}
	return 0;
}
