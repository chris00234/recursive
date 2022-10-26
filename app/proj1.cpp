#include <unordered_map>
#include <string>



std::string find_string(std::string s1, std::string s2, std::string s3)
{
	std::string result{};
	for (char c : s1)
	{
		result += c;
	}
	for (char c : s2)
	{
		result += c;
	}
	for (char c : s3)
	{
		result += c;
	}

	for (int i = 0; i < result.length(); i++)
	{

		for (int j = 0; j < i; j++)
		{
			if (result[i] == result[j])
			{
				result.erase(i, 1);
			}

		}

	}
	return result;
}

void set_map(std::string s1, std::string s2, std::string s3, std::string& num, std::unordered_map<char, unsigned>& mapping)
{
	std::string str = find_string(s1, s2, s3);
	for (int i = 0; i < str.length(); i++)
	{
		mapping[str[i]] = std::stoi(num.substr(i, 1));
	}
}


int string_to_int(std::string s, std::unordered_map<char, unsigned>& mapping)
{
	unsigned num = 0;
	int digit = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		num += mapping[s[i]] * digit;
		digit *= 10;
	}
	return num;
}

bool check_sum(const std::string& s1, const std::string& s2, const std::string& s3, std::unordered_map<char, unsigned>& mapping)
{
	if ((string_to_int(s1, mapping) + string_to_int(s2, mapping)) == string_to_int(s3, mapping))
		return true;
	return false;
}


void perm(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned>& mapping,
	std::string& nums, int l, int r)
{

	if (l == r)
	{
		if (check_sum(s1, s2, s3, mapping))
		{
			return;
		}
		set_map(s1, s2, s3, nums, mapping);
	
	}


	for (int i = l; i <= r; i++)
	{

		std::swap(nums[l], nums[i]);


		perm(s1, s2, s3, mapping, nums, l + 1, r);


		std::swap(nums[l], nums[i]);
	}
}

bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned>& mapping)
{
	bool found = false;
	std::string num = "0123456789";

	set_map(s1, s2, s3, num, mapping);
	perm(s1, s2, s3, mapping, num, 0, num.size() - 1);
	if (check_sum(s1, s2, s3, mapping))
	{
		found = true;
	}

	return found;

}


