SELECT p.product_code, sum(p.price*o.sales_amount) as sales
FROM offline_sale as o
left join product as p
on p.product_id = o.product_id
group by product_code
order by sales desc, p.product_code;