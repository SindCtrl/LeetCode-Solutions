LeetCode 1344 - Angle Between Hands of a Clock

Concept:
Minute Hand:
1 minute = 6 degrees

Hour Hand:
1 hour = 30 degrees
1 minute = 0.5 degrees

Formula:
minuteAngle = minutes * 6
hourAngle = hour * 30 + minutes * 0.5

angle = |hourAngle - minuteAngle|
answer = min(angle, 360 - angle)

Time Complexity: O(1)
Space Complexity: O(1)
