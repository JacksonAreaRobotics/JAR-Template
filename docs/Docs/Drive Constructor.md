---
title: Drive Constructor
layout: default
nav_order: 1
parent: Docs
---

#Docs

##setup construction

<html lang="en-us">
    <head>
      <link rel="stylesheet" href="/assets/custom.css">
    </head>
    <body>

{% tabs log %}

{% tab log php %}
```php
var_dump('hello');
```
{% endtab %}

{% tab log js %}
```javascript
console.log('hello');
```
{% endtab %}

{% tab log ruby %}
```javascript
pputs 'hello'
```
{% endtab %}

{% endtabs %}



{% tabs data-struct %}

{% tab data-struct yaml %}
```yaml
hello:
  - 'whatsup'
  - 'hi'
```
{% endtab %}

{% tab data-struct json %}
```json
{
    "hello": ["whatsup", "hi"]
}
```
{% endtab %}

{% endtabs %}


        <script src="/assets/tabs.js"></script>
    </body>
</html>