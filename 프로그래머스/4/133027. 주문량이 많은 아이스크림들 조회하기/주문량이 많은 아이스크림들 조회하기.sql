-- 코드를 입력하세요
#first_half flavor 기본키, shipment_id 외래키
#july shipment_id 기본키, flavor 외래키, 7월에는 중복됨 같은 맛인데. 다른 출하번호
SELECT      f.flavor
from        first_half f inner join july j on f.flavor = j.flavor
group by    f.flavor
order by    sum(f.total_order + j.total_order) desc
limit       3;