class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if not (nums1 or nums2): return 0

        total_len = len(nums1) + len(nums2)
        if total_len % 2 == 0:
            return (self.get_median(nums1, nums2, total_len // 2) + 
                    self.get_median(nums1, nums2, total_len // 2 + 1)) / 2
        else:
            return self.get_median(nums1, nums2, total_len // 2 + 1)
        
    def get_median(self, nums1, nums2, k):
        while nums1 and nums2 and (k > 1):
            half_len1 = len(nums1) // 2
            half_len2 = len(nums2) // 2
            if nums2[half_len2] >= nums1[half_len1]:
                # drop the right half of nums2
                if half_len1 + half_len2 + 1 >= k:
                    nums2 = nums2[:half_len2]
                else: # drop the left half of nums1
                    k -= half_len1 + 1
                    nums1 = nums1[half_len1 + 1:]
            else:
                # drop the right half of nums1
                if half_len1 + half_len2 + 1 >= k:
                    nums1 = nums1[:half_len1]
                else: # drop the left half of nums2
                    k -= half_len2 + 1
                    nums2 = nums2[half_len2 + 1:]

        if not nums1:
            return nums2[k - 1]
        if not nums2:
            return nums1[k - 1]
        if k <= 1:
            return min(nums1[0], nums2[0])