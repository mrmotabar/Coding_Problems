<?php

function getPaginationButtons($total_items, $per_page, $current_page)
{
    // Implement getPaginationButtons function here
    $ret = [];
    $max_n = ceil($total_items / $per_page);
    if ($current_page != 1) {
        array_push($ret, array("text" => "prev", "number" => $current_page - 1));
    }
    array_push($ret, array("text" => "1", "number" => 1));
    if ($current_page >= 6) {
        array_push($ret, array("text" => "..."));
    } else {
        for ($i = 2; $i < max($current_page - 2, 2); $i++) {
            array_push($ret, array("text" => "$i", "number" => $i));
        }
    }
    for ($i = max($current_page - 2, 2); $i < min($current_page + 3, $max_n - 1); $i++) {
        array_push($ret, array("text" => "$i", "number" => $i));
    }
    if ($current_page <= $max_n - 5) {
        array_push($ret, array("text" => "..."));
    } else {
        for ($i = min($current_page + 3, $max_n - 1); $i < $max_n; $i++) {
            array_push($ret, array("text" => "$i", "number" => $i));
        }
    }
    array_push($ret, array("text" => "$max_n", "number" => $max_n));
    if ($current_page != $max_n) {
        array_push($ret, array("text" => "next", "number" => $current_page + 1));
    }
    return $ret;
}

function renderPagination($pagination_template, $total_items, $per_page, $current_page, $base_url)
{
    $pages = getPaginationButtons($total_items, $per_page, $current_page);
    $html = '';
    foreach ($pages as $page) {
        $page['text'] = str_replace(['prev', 'next'], ['&laquo;', '&raquo;'], $page['text']);
        if (in_array($page['text'], ['&laquo;', '...', '&raquo;'])) {
            $html .= '<li class="page-item">
              <a class="page-link" href="' . (isset($page['number']) ? $base_url . $page['number'] : '#') . '">
                <span aria-hidden="true">' . $page['text'] . '</span>
              </a>
            </li>';
        } else {
            $html .= '<li class="page-item' . ($page['number'] == $current_page ? ' active' : '') . '"><a class="page-link" href="' . $base_url . $page['number'] . '">' . $page['number'] . '</a></li>';
        }
    }

    return str_replace('{{ @pages }}', $html, $pagination_template);
}
