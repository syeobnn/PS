SELECT p.product_code, sum(p.price*o.sales_amount) as sales
FROM offline_sale as o
join product as p
on p.product_id = o.product_id
group by p.product_code
order by sales desc, p.product_code;