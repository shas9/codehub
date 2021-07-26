


<!DOCTYPE html>
<html>
<head>
    <title>
        Ruet junior contest 1 - Virtual Judge
    </title>

    




















  
    
    
  


<meta http-equiv="content-type" content="text/html; charset=UTF-8"/>
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">

<meta name="keywords" content="Online Judge, vjudge, OJ, Virtual Judge, Replay Contest, ICPC, OnlineJudge, JudgeOnline, Coding, Algorithm, ç«èµ, ç®æ³, POJ, ZOJ, UVALive, SGU, URAL, HUST, SPOJ, HDU, HYSBZ, UVA, CodeForces, Z-Trening, Aizu, LightOJ, UESTC, NBUT, FZU, CSU, SCU, ACdream, CodeChef, CF::Gym, OpenJudge, Kattis, HihoCoder, HIT, HRBUST, EIJudge, AtCoder, HackerRank, 51Nod" />
<meta name="author" content="chaoshxxu" />
<meta name="robots" content="index, follow" />

<link rel="shortcut icon" href="/static/images/logo.ico" />
<link rel="stylesheet" type="text/css" href="/static/bundle/vendor.5c5e2cc7ee1f8481b3db.css" />
<link rel="stylesheet" type="text/css" href="/static/bundle/app.4d386860f5149bc24359.css" />


    <meta property="og:url" content="https://vjudge.net/contest/201399"/>
    <meta property="og:type" content="website"/>
    <meta property="og:title" content="Ruet junior contest 1 - Virtual Judge"/>
    <meta property="og:description" content="Contest [Ruet junior contest 1] in Virtual Judge"/>
    <meta property="og:image" content="https://vjudge.net//static/images/logo.ico"/>
</head>

<body>




















<nav class="navbar navbar-dark bg-inverse">
    <button class="navbar-toggler hidden-md-up" type="button" data-toggle="collapse"
            data-target="#navbarResponsive"></button>
    <div class="collapse navbar-toggleable-sm" id="navbarResponsive">
        <a class="navbar-brand" href="/">
            <img src="/static/images/logo.ico" height="30"/>
            Home
        </a>
        <ul class="nav navbar-nav">
            <li class="nav-item" id="nav-problem">
                <a class="nav-link" href="/problem">Problem</a>
            </li>
            <li class="nav-item" id="nav-status">
                <a class="nav-link" href="/status">Status</a>
            </li>
            <li class="nav-item" id="nav-contest">
                <a class="nav-link" href="/contest">Contest</a>
            </li>
            <li class="nav-item" id="nav-user">
                <a class="nav-link" href="/user">User</a>
            </li>
            <li class="nav-item" id="nav-group">
                <a class="nav-link" href="/group">Group</a>
            </li>
            <li class="nav-item" id="nav-comment">
                <a class="nav-link" href="/comment">Forum</a>
            </li>
            <li class="nav-item" id="nav-article">
                <a class="nav-link" href="/article">Article</a>
            </li>
            
            
                
                    <li class="nav-item float-xs-right">
                        <a class="nav-link logout" href="javascript:void(0)">Logout</a>
                    </li>
                    <li class="nav-item dropdown float-xs-right">
                        <a class="nav-link dropdown-toggle" href="javascript:void(0)"
                           id="userNameDropdown" data-toggle="dropdown">RUET_Beginner101</a>
                        <div class="dropdown-menu dropdown-menu-right user-dropdown">
                            <a class="dropdown-item"
                               href="/user/RUET_Beginner101">Profile</a>
                            <a class="dropdown-item update-profile" href="javascript:void(0)">Update</a>
                            <a class="dropdown-item message" href="/message">Message</a>
                        </div>
                    </li>
                
                
            
        </ul>
    </div>
</nav>



<div class="container" style="margin-top: 30px;">
    
        <div class="row alert alert-info" id="contest-announcement" style="display: none;"></div>
    

    <div class="row card" id="time-info">
        <div class="row">
            <div class="col-xs-3 text-xs-left">
                <b>Begin:</b>
                <span class="timestamp">1511697000000</span>
            </div>
            <div class="col-xs-6 text-xs-center">
                <h3>
                    
                    
                    Ruet junior contest 1
                </h3>
            </div>
            <div class="col-xs-3 text-xs-right">
                <b>End:</b>
                <span class="timestamp">1511709600000</span>
            </div>
        </div>
        <div class="row" id="contest-time-slider-container">
            <input id="contest-time"
                   type="text"
                   data-slider-id='contest-time-slider'
                   style="display: none;"/>
        </div>
        <div class="row">
            <div class="col-xs-3 text-xs-left" id="info-elapsed">
                <b>Elapsed:</b>
                <span class="elapsed" id="span-elapsed"></span>
            </div>
            <div class="col-xs-6 text-xs-center">
                <span id="info-running"></span>
            </div>
            <div class="col-xs-3 text-xs-right" id="info-remaining">
                <b>Remaining:</b>
                <span class="remaining" id="span-remaining"></span>
            </div>
        </div>
    </div>

    
        <div class="row">
            <!-- Nav tabs -->
            <ul class="nav nav-tabs" role="tablist" id="contest-tabs">
                <li class="nav-item">
                    <a class="nav-link active" data-toggle="tab" href="#overview" section="overview"
                       role="tab">Overview</a>
                </li>

                
                    <li class="nav-item">
                        <a class="nav-link" data-toggle="tab" href="#problem" section="problem" role="tab">Problem</a>
                    </li>
                

                
                    <li class="nav-item">
                        <a class="nav-link" data-toggle="tab" href="#status" section="status" role="tab">Status</a>
                    </li>
                

                
                    <li class="nav-item">
                        <a class="nav-link" data-toggle="tab" href="#rank" section="rank" role="tab">
                            Rank <i class='fa fa-refresh fa-spin'></i>
                        </a>
                    </li>
                

                <li class="nav-item">
                    <a class="nav-link" data-toggle="tab" href="#discuss" section="discuss" role="tab"
                       rel="#discuss" data-disqus-identifier="contest/201399">Discuss</a>
                </li>

                <li class="text-xs-right">
                    <div class="btn-group" role="group">
                        
                            <button type="button" class="btn btn-secondary" id="btn-setting">Setting</button>
                        
                        <button type="button" class="btn btn-secondary" id="btn-favorite"><i></i>Favorite</button>
                        
                        
                    </div>
                </li>
            </ul>

            <!-- Tab panes -->
            <div class="tab-content">
                <div class="tab-pane in active" id="overview" role="tabpanel">
                    



















<div id="contest_overview" class="container">

    
        <div class="row">
            <table id="contest-problems" class="table table-striped table-bordered table-responsive" cellspacing="0"
                   width="100%">
                <thead>
                <tr>
                    <th class="my-stat"></th>
                    <th class="all-stat">Stat</th>
                    <th class="prob-num">#</th>
                    
                    
                    <th class="prob-title text-xl-left">Title</th>
                </tr>
                </thead>
                <tbody>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">A</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/A">
                                Karen and Coffee
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">B</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/B">
                                Queries about less or equal elements
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">C</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/C">
                                Divisiblity of Differences
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">D</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/D">
                                Santa Claus and a Place in a Class
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">E</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/E">
                                Arpa and an exam about geometry
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">F</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/F">
                                Anton and Fairy Tale
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">G</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/G">
                                Chloe and the sequence
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">H</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/H">
                                k-Tree
                            </a>
                        </td>
                    </tr>
                
                    <tr>
                        <td class="my-stat"></td>
                        <td class="all-stat"></td>
                        <td class="prob-num text-xs-center">I</td>
                        
                        
                        <td class="prob-title">
                            <a href="#problem/I">
                                Maximum of Maximums of Minimums
                            </a>
                        </td>
                    </tr>
                
                </tbody>
            </table>
        </div>
    

    <div class="row text-xs-right" id="contest-manager">
        <div class="fb-like"
             data-href="https://vjudge.net/contest/201399"
             data-layout="button_count"
             data-action="like"
             data-size="small"
             data-show-faces="true"
             data-share="true"></div>
    </div>

    <div class="row card" id="contest-description" style="display: none"></div>

</div>

                </div>
                
                    <div class="tab-pane" id="problem" role="tabpanel">
                        



















<div id="contest_problem" class="container">
    <div class="row">
        <div class="col-md-3 container" id="prob-left-panel">
            <ul class="nav nav-pills row" id="problem-nav">
                
                    <li class="nav-item">
                        <a num="A"
                           class="nav-link"
                           href="#problem/A">A</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="B"
                           class="nav-link"
                           href="#problem/B">B</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="C"
                           class="nav-link"
                           href="#problem/C">C</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="D"
                           class="nav-link"
                           href="#problem/D">D</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="E"
                           class="nav-link"
                           href="#problem/E">E</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="F"
                           class="nav-link"
                           href="#problem/F">F</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="G"
                           class="nav-link"
                           href="#problem/G">G</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="H"
                           class="nav-link"
                           href="#problem/H">H</a>
                    </li>
                
                    <li class="nav-item">
                        <a num="I"
                           class="nav-link"
                           href="#problem/I">I</a>
                    </li>
                
            </ul>

            <div class="alert alert-danger row" role="alert" id="prob-alert" style="display: none"></div>

            <div id="prob-operation" class="row">
                <div class="container">
                    <div class="row">
                        <div class="col-xs-12">
                            <button type="button" class="btn btn-primary" id="problem-submit">Submit</button>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6">
                            <a href="#status//A/0/CPP" class="btn btn-secondary" id="btn-contest-status">Status</a>
                        </div>
                        <div class="col-xs-6">
                            <a href="#status/Isun/A/0/CPP" class="btn btn-secondary" id="btn-contest-my-status">My
                                Status</a>
                        </div>
                    </div>
                </div>
            </div>

            <div id="prob-properties" class="row">
                <div class="container">
                    <dl class="card row"></dl>
                </div>
            </div>

            <div id="prob-descriptions" class="row">
                <span>Choose a description for participants:</span>
                <div class="list-group" id="prob-descs"></div>
            </div>
        </div>
        <div class="col-md-9 container" id="prob-right-panel">
            <div class="row">
                <div id="prob-title-contest">
                    <h2 id="problem-title"></h2>
                    <span class="origin">
                        <a id="problem-origin" href="#" target="_blank"></a>
                    </span>
                </div>
            </div>
            <div class="row" id="frame-description-container"></div>
        </div>
    </div>

</div>

                    </div>
                
                
                    <div class="tab-pane" id="status" role="tabpanel">
                        



















<div id="contest_status" class="container">
    <div class="row" id="right-panel">
        <table id="listStatus" class="table table-striped table-bordered table-responsive" cellspacing="0" width="100%">
            <thead>
            <tr>
                <th class="run-id hidden-lg-down">Run ID</th>
                <th class="username">
                    Username<br/>
                    <input type="text" id="un" name="un" class="search_text" style="width:100%"/>
                </th>
                <th class="num">
                    Prob<br/>
                    <select id="contest-status-num" name="num" class="custom-select">
                        <option value="-">All</option>
                    </select>
                </th>
                <th class="status">
                    Result
                    <br/>
                    <select id="res" name="res" class="custom-select">
                        <option value="0">All</option>
                        <option value="1">Accepted</option>
                        <option value="2">Presentation Error</option>
                        <option value="3">Wrong Answer</option>
                        <option value="4">Time Limit Exceed</option>
                        <option value="5">Memory Limit Exceed</option>
                        <option value="6">Output Limit Exceed</option>
                        <option value="7">Runtime Error</option>
                        <option value="8">Compile Error</option>
                        <option value="9">Unknown Error</option>
                        <option value="10">Submit Error</option>
                        <option value="11">Queuing && Judging</option>
                    </select>
                </th>
                <th class="runtime">Time<br>(ms)</th>
                <th class="memory">Mem<br>(MB)</th>
                <th class="length hidden-lg-down">Length</th>
                <th class="language">
                    Lang
                    <br/>
                    <select name="language" id="language" class="custom-select">
                        <option value="">All</option>
                        <option value="CPP">C++</option>
                        <option value="C">C</option>
                        <option value="JAVA">Java</option>
                        <option value="PASCAL">Pascal</option>
                        <option value="PYTHON">Python</option>
                        <option value="CSHARP">C#</option>
                        <option value="RUBY">Ruby</option>
                        <option value="OTHER">Other</option>
                    </select>
                </th>
                <th class="date">Submit Time</th>
            </tr>
            </thead>
            <tbody></tbody>
        </table>
        <input type="button" class="btn btn-secondary btn-md" id="rejudge-all" value="Rejudge"
               style="display: none"/>
        <input type="button" class="btn btn-secondary btn-md" id="reset" value="Reset" style="display: none"/>
        <input type="button" class="btn btn-secondary btn-md" id="filter" value="Filter" style="display: none"/>
    </div>
</div>

                    </div>
                
                
                    <div class="tab-pane" id="rank" role="tabpanel">
                        




















<div id="contest_rank">

    <table id="contest-rank-table" cellspacing="1"></table>
    <table id="contest-rank-table-export"></table>

    <div class="rank_tool">
        <img src="/static/images/find_me.png" id="img_find_me" title="Find me" height="55"/>
    </div>

</div>

                    </div>
                
                <div class="tab-pane" id="discuss" role="tabpanel">
                    



















<div id="contest_discuss"></div>

                </div>
            </div>

            <div class="rank_tool">
                <span id="img_go_top" title="Go to top"></span>
            </div>
        </div>
    
    

</div>

<textarea style="display: none" name="dataJson">{"id":201399,"title":"Ruet junior contest 1","type":0,"openness":0,"authStatus":2,"begin":1511697000000,"end":1511709600000,"createTime":1511696694000,"started":true,"ended":false,"managerId":125432,"managerName":"Nobel_ruetttt","fav":false,"description":{"format":"HTML","content":""},"announcement":"","problems":[{"pid":0,"title":"Karen and Coffee","oj":"CodeForces","num":"A","publicDescId":81874,"publicDescVersion":1511695683000,"properties":{"Time limit":"2500 ms","Memory limit":"524288 kB"},"weight":1},{"pid":0,"title":"Queries about less or equal elements","oj":"CodeForces","num":"B","publicDescId":58536,"publicDescVersion":1511590761000,"properties":{"Time limit":"2000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"Divisiblity of Differences","oj":"CodeForces","num":"C","publicDescId":91306,"publicDescVersion":1511456531000,"properties":{"Time limit":"1000 ms","Memory limit":"524288 kB"},"weight":1},{"pid":0,"title":"Santa Claus and a Place in a Class","oj":"CodeForces","num":"D","publicDescId":74644,"publicDescVersion":1511696112000,"properties":{"Time limit":"2000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"Arpa and an exam about geometry","oj":"CodeForces","num":"E","publicDescId":89785,"publicDescVersion":1511336049000,"properties":{"Time limit":"2000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"Anton and Fairy Tale","oj":"CodeForces","num":"F","publicDescId":77507,"publicDescVersion":1511266080000,"properties":{"Time limit":"1000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"Chloe and the sequence","oj":"CodeForces","num":"G","publicDescId":74315,"publicDescVersion":1511185637000,"properties":{"Time limit":"1000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"k-Tree","oj":"CodeForces","num":"H","publicDescId":43230,"publicDescVersion":1511696548000,"properties":{"Time limit":"1000 ms","Memory limit":"262144 kB"},"weight":1},{"pid":0,"title":"Maximum of Maximums of Minimums","oj":"CodeForces","num":"I","publicDescId":91239,"publicDescVersion":1511270345000,"properties":{"Time limit":"1000 ms","Memory limit":"262144 kB"},"weight":1}],"problemsHash":"a4f59468054bb8c4578d6d13d88c9a99","privatePeerContestIds":[],"enableTimeMachine":true,"sumTime":true,"penalty":1200,"partialScore":false,"customizedWeight":false,"showPeers":false}</textarea>
<script type="text/javascript">moduleName = "./contest/view/view";</script>




















<div class="body-footer">
    <br/>All Copyright Reserved ©2010-2017 <a href="mailto:is.un@qq.com">Xu Han</a>
    <br/>Server Time: <span class="currentTimeTZ"></span>
</div>

<input name="version" type="hidden" value="1511624195368"/>

    <input id="username" name="username" type="hidden" value="RUET_Beginner101"/>
    <input id="userId" name="userId" type="hidden" value="161561"/>
    <input id="sup" name="sup" type="hidden" value="0"/>
    <input id="newMessage" name="newMessage" type="hidden" value="false"/>


<span id="img-support" title="Feedback"></span>
<script type="text/javascript">basePath = "";</script>
<script type="text/javascript">imagesRoot = "/static/images";</script>
<script src="/static/bundle/loader.d41d8cd98f00b204e980.js?1511624195368"></script>
<script src="/static/bundle/vendor.5c5e2cc7ee1f8481b3db.js"></script>
<script src="/static/bundle/app.4d386860f5149bc24359.js"></script>
<script>
    (function (i, s, o, g, r, a, m) {
        i['GoogleAnalyticsObject'] = r;
        i[r] = i[r] || function () {
                (i[r].q = i[r].q || []).push(arguments)
            }, i[r].l = 1 * new Date();
        a = s.createElement(o),
            m = s.getElementsByTagName(o)[0];
        a.async = 1;
        a.src = g;
        m.parentNode.insertBefore(a, m)
    })(window, document, 'script', 'https://www.google-analytics.com/analytics.js', 'ga');
    ga('create', 'UA-13231844-2', 'auto');
    
    ga('set', 'userId', 'RUET_Beginner101');
    
    ga('send', 'pageview');
</script>


<div id="fb-root"></div>
<script>(function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id)) return;
    js = d.createElement(s); js.id = id;
    js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.8";
    fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

</body>
</html>
