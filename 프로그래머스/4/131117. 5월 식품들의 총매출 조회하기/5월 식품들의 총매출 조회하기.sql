SELECT  fo.product_id, fp.product_name, sum(fp.price * fo.amount) as mach
FROM    food_product as fp 
        join food_order as fo on fp.product_id = fo.product_id
WHERE   date_format(fo.produce_date, '%Y-%m') = '2022-05' #%Y 부분에 소문자 꼭 써주기
group by fo.product_id
order by mach desc, fo.product_id asc;