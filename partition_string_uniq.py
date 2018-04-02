"""
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts."""

# "ababcbaca defegde hijhklij"
#  0       8 9
# a -> 8
# b -> 5
# c -> 7
# curr_el = 8
# last_segment_idx = 0
# min_required_idx = 8

# abcajkblmjn
# abcajkblmj n

def partition_string(inp_string)->list:
	
	if not inp_string:
		return []
	
	if len(inp_string) ==  1:
		return [1]
	
	last_idx = {}
	
	for i in range(len(inp_string)-1,-1,-1):
		if inp_string[i] not in last_idx.keys():
			last_idx[inp_string[i]] = i
			
	curr_el = 0
	last_segment_idx = 0
	out_list = []
	min_required_idx = last_idx[inp_string[curr_el]]
	
	while curr_el < len(inp_string):
		while curr_el < min_required_idx:
		    curr_min_required = last_idx[inp_string[curr_el]]
			if curr_min_required > min_required_idx:
				min_required_idx = curr_min_required
			curr_el+=1
		
		out_list.append(min_required_idx - last_segment_idx + 1)
		last_segment_idx = min_required_idx + 1
		curr_el = last_segment_idx
		min_required_idx = last_idx[inp_string[curr_el]]

	return out_list