class Solution {
public:
    int minCharacters(string a, string b) {

		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

		cnt1 = cnt2 = cnt3 = cnt4 = a.size() + b.size();

		for(ll i = 1; i < 26; i++)
		{
			int ret = 0;

			for(auto it: a)
			{
				if(it - 'a' >= i) ret++;
			}

			for(auto it: b)
			{
				if(it - 'a' < i) ret++;
			}

			cnt1 = min(cnt1, ret);
		}

		for(ll i = 1; i < 26; i++)
		{
			int ret = 0;

			for(auto it: b)
			{
				if(it - 'a' >= i) ret++;
			}

			for(auto it: a)
			{
				if(it - 'a' < i) ret++;
			}

			cnt2 = min(cnt2, ret);
		}

		for(ll i = 0; i < 26; i++)
		{
			int ret = 0;

			for(auto it: b)
			{
				if(it - 'a' != i) ret++;
			}

			cnt3 = min(cnt3, ret);
		}

		for(ll i = 0; i < 26; i++)
		{
			int ret = 0;

			for(auto it: a)
			{
				if(it - 'a' != i) ret++;
			}

			cnt4 = min(cnt4, ret);
		}

		cnt3 += cnt4;

		return min(cnt1, min(cnt2,cnt3));
    }
};
