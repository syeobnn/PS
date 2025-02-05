SELECT b.book_id, a.author_name, date_format(b.published_date,'%Y-%m-%d') as published_date
FROM book as b
join author as a on a.author_id = b.author_id
WHERE b.category = '경제'
ORDER BY published_date ASC;